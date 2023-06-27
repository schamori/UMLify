
$(document).ready(function () {

	getSessionID();
	downloadUML();
});

function getSessionID() {
	$.ajax({
		url: "getSessionID.php",
		success: function (data) {
			drawUML(data);
		}
	})
}

function drawUML(sessionID) {
	$.ajax({
		url: "uploads/" + sessionID + "/result.json",
		dataType: "json",
		success: function (data) {
			var classes = data.classes;
			var html = '<div class="container"><div class="row">';
			for (var className in classes) {
				var classData = classes[className];
				html += '<div class="col-2 m-4">';
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
						html += '<li class="list-group-item ' + cssClass + '">' + attribute + "</li>";
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
						html += '<li class="list-group-item ' + cssClass + '">' + methodName + "(" + parameters + ")" + "</li>";
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

	$('#pic').click(function () {
		function download(canvas, filename) {
			const data = canvas.toDataURL("image/png;base64");
			donwloadLink = document.querySelector("#pic");
			donwloadLink.download = filename;
			donwloadLink.href = data;
		}
		download(svgToCanvas($("body"), "hopa"));
	})
}

function svgToCanvas(targetElem) {
	var nodesToRecover = [];
	var nodesToRemove = [];

	var svgElem = targetElem.find('svg');

	svgElem.each(function (index, node) {
		var parentNode = node.parentNode;
		var svg = parentNode.innerHTML;

		var canvas = document.createElement('canvas');

		canvg(canvas, svg);

		nodesToRecover.push({
			parent: parentNode,
			child: node
		});
		parentNode.removeChild(node);

		nodesToRemove.push({
			parent: parentNode,
			child: canvas
		});

		parentNode.appendChild(canvas);
	});

	html2canvas(targetElem, {
		onrendered: function (canvas) {
			var ctx = canvas.getContext('2d');
			ctx.webkitImageSmoothingEnabled = false;
			ctx.mozImageSmoothingEnabled = false;
			ctx.imageSmoothingEnabled = false;
		}
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