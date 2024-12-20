$(document).ready(function () {
	getSessionID();
	downloadUML();
});

function getSessionID(){
	$.ajax({
		url: "getSessionID.php",
		success: function (data) {
			drawUML(data);
		}
	})
}

function htmlEntities(str) {
    return str.replace(/&/g, '&amp;')
              .replace(/</g, '&lt;')
              .replace(/>/g, '&gt;')
              .replace(/"/g, '&quot;')
              .replace(/'/g, '&#39;');
}

function escapeAngleBracketsAndColon(str) {
    return str.replace(/</g, '&lt;').replace(/>/g, '&gt;').replace(/:/g, '&nbsp;:');
}

function drawUML(sessionID) {
	$.ajax({
		url: "uploads/"+sessionID+"/result.json",
		dataType: "json",
		success: function (data) {
			var classes = data.classes;
			var html = '<div class="container"><div class="row">';
			for (var className in classes) {
				var classData = classes[className];
				html += '<div class="col-5 m-4">';
				html += '<div id="' + className + '"class="card">';
				html += '<div class="card-header fw-bold">' + className + "</div>";
				if (classData.attributes.length > 0) {
					html += '<div class="card-header">Attributes</div>';
					html += '<ul class="list-group list-group-flush">';
					for (var i = 0; i < classData.attributes.length; i++) {
						var attribute = classData.attributes[i];
						var attributeType = attribute.charAt(0);
						var cssClass = "";
						if (attributeType === "+") {
							cssClass = "public-attribute";
						} else if (attributeType === "#") {
							cssClass = "protected-attribute";
						} else if (attributeType === "-") {
							cssClass = "private-attribute";
						}
						html += '<li class="list-group-item ' + cssClass + '">' + htmlEntities(attribute) + "</li>";
					}
					html += "</ul>";
				}
				if (classData.methods.length > 0) {
					html += '<div class="card-header">Methods</div>';
					html += '<ul class="list-group list-group-flush">';
					for (var i = 0; i < classData.methods.length; i++) {
						var method = classData.methods[i];
						var methodName = method.name;
						var parameters = method.parameters;
						var methodType = methodName.charAt(0);
						var cssClass = "";
						if (methodType === "+") {
							cssClass = "public-method";
						} else if (methodType === "#") {
							cssClass = "protected-method";
						} else if (methodType === "-") {
							cssClass = "private-method";
						}
						html += '<li class="list-group-item ' + cssClass + '">' + methodName + "(" + escapeAngleBracketsAndColon(String(parameters)) + ")" + "</li>";


					}
					html += "</ul>";
				}
				html += "</div>";
				html += "</div>";
			}
			html += "</div></div>";
			console.log(classes);
			$("#uml").html(html);
			$(".card").draggable({
				containment: "#myDiv",
			});
			lines(classes);
		},
	});
}

function downloadUML() {
	$('#pic').click(function() {
        htmlToImage.toJpeg($('#uml')[0], { quality: 0.95 })
            .then(function (dataUrl) {
                var link = document.createElement('a');
                link.download = 'my-image-name.jpeg';
                link.href = dataUrl;
                link.click();
            });
    });
}

function lines(classes) {
	$(function () {
		for (var className in classes) {
			if (classes[className].parent.length > 0) {
				// console.log(classes[className].parent);
				let line = new LeaderLine(document.getElementById(className), document.getElementById(classes[className].parent), { path: "grid", color: "black" });
				
				let start = "#" + className;
				let end = "#" + classes[className].parent;
				$("#uml").append(line);
				// console.log(start, end);
				$("#uml").append(line);
				$(start + ", " + end).draggable({
					drag: function () {
						line.position();
					},
				});
			}
		}
	});
}