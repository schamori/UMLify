import os
import re
import json

def remove_unnecessary_content(content):
    single_line_comment_pattern = r'//.*$'
    multi_line_comment_pattern = r'/\*.*\*/'
    preprocessor_pattern = r'#.*$'
    content = re.sub(single_line_comment_pattern, '', content, flags=re.MULTILINE)
    content = re.sub(multi_line_comment_pattern, '', content, flags=re.DOTALL)
    content = re.sub(preprocessor_pattern, '', content, flags=re.MULTILINE)
    content = content.replace("\n", "")
    return content


def get_variable_content(variable):
    if variable[0]:
        return f"{variable[0]} {variable[2]}", variable[3], variable[4]
    elif variable[1]:
        return f"{variable[1]} {variable[2]}", variable[3], variable[4]
    else:
        return variable[2], variable[3], variable[4]

def content2dict(content, class_data):
    content = remove_unnecessary_content(content)
    class_regex = r"class\s+(\w+)\s*?(?:\:\s*\s*(?:public|private|protected)\s+(\w+)\s*,?)*\s*(\{[^{}]*\});"
    classes = re.findall(class_regex, content)
    for class_match in classes:
        # ------------- Class Names ---------------- #
        class_name = class_match[0]
        class_data["classes"][class_name] = dict()
        # ----------- Parent ------------- #
        # Todo multiple parents
        # If there is no parent -> parent: ""
        class_data["classes"][class_name]["parent"] = class_match[1]

        # -------------- Inner Class Part -------------- #
        inner = class_match[2]
        variable = r"(?:const\s+|(enum)\s+|(struct)\s+)?(?:\w+::)?(\w+)\s+((?:\*|&)+\s*)*(\w+)\s*(?:\[(?:\s*\d+\s*)?\])?\s*"

        # These regex expressions describe the whole part after e.g private: until } or protected: or public:
        access_modifiers = [(r"private:(.*?)(?:protected:|public:|\})", "-"),
                    (r"public:(.*?)(?:private:|protected:|\})", "+"),
                    (r"protected:(.*?)(?:private:|public:|\})", "#")]
        class_data["classes"][class_name]["attributes"] = list()
        class_data["classes"][class_name]["methods"] = list()
        for pattern, symbol in access_modifiers:
            inner_access = re.findall(pattern, inner)
            if len(inner_access) > 0:
                inner_access = inner_access[0]
                # ---------------- Attributes ---------------------- #
                attribute_pattern = f"{variable};"
                attribute_matches = re.findall(attribute_pattern, inner_access)
                for attribute_match in attribute_matches:
                    data_type, pointer, name = get_variable_content(attribute_match)
                    class_data["classes"][class_name]["attributes"].append(f"{symbol}{data_type} : {pointer}{name}")

                #Todo
                # ---------------- Methods ---------------------- #
                # ---------------- Relations ---------------------- #
    return class_data


directory = 'uploads'
h_pattern = r'.*\.h$'
class_data = dict()
class_data["classes"] = dict()
for root, dirs, files in os.walk(directory):
    for file in files:
        if re.match(h_pattern, file):
            with open(os.path.join(root, file)) as f:
                content = f.read()
            class_data = content2dict(content, class_data)

with open("result.json", 'w') as fp:
    json.dump(class_data, fp)