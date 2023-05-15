$(document).ready(function() {
    drawUML();
});

function drawUML() {
    console.log("ZEICHNEN");
    $.ajax({
		url: "result.json",
		dataType: "json",
		success: function (data) {
			var goMake = go.GraphObject.make;
			var myDiagram = goMake(go.Diagram, "myDiagramDiv", {
				initialContentAlignment: go.Spot.Center,
				"undoManager.isEnabled": true,
			});

			myDiagram.nodeTemplate = goMake(
				go.Node,
				"Auto",
				goMake(go.Shape, { fill: "lightblue" }),
				goMake(
					go.Panel,
					"Table",
					{ defaultRowSeparatorStroke: "black" },
					goMake(go.TextBlock, { row: 0, columnSpan: 2, margin: 3, alignment: go.Spot.Center }, new go.Binding("text", "key")),
					goMake(go.TextBlock, "Properties", { row: 1, font: "italic 10pt sans-serif" }),
					goMake(
						go.TextBlock,
						{ row: 2, columnSpan: 2 },
						new go.Binding("text", "", function (data) {
							var s = "";
							if (data.attributes) {
								for (var i = 0; i < data.attributes.length; i++) {
									var attribute = data.attributes[i];
									s += attribute + "\n";
								}
							}
							return s;
						})
					),
					goMake(go.TextBlock, "Methods", { row: 3, font: "italic 10pt sans-serif" }),
					goMake(
						go.TextBlock,
						{ row: 4, columnSpan: 2 },
						new go.Binding("text", "", function (data) {
							var s = "";
							if (data.methods) {
								for (var i = 0; i < data.methods.length; i++) {
									var method = data.methods[i];
									s += method.name + "(";
									if (method.paramters) {
										s += method.paramters.join(", ");
									}
									s += ")\n";
								}
							}
							return s;
						})
					)
				)
			);

			myDiagram.linkTemplate = goMake(go.Link, { routing: go.Link.Orthogonal }, goMake(go.Shape), goMake(go.Shape, { toArrow: "Standard" }));

			var nodeDataArray = [];
			var linkDataArray = [];

			jQuery.each(data, function (key, value) {
				if (key !== "relations") {
					var nodeData = {
						key: key,
						attributes: value.attributes,
						methods: value.methods,
					};
					nodeDataArray.push(nodeData);
				}
			});

			jQuery.each(data.relations, function (key, value) {
				var linkData = {
					from: key,
					to: value,
				};
				linkDataArray.push(linkData);
			});

			myDiagram.model = new go.GraphLinksModel(nodeDataArray, linkDataArray);
		},
	});
	$(".card").draggable();
    deleteFiles();
};

function deleteFiles(){
  $.ajax({
    url: 'deleteFilesFromServer.php',
    success: function(response) {
      console.log("Gelöscht");
    }
  });
}