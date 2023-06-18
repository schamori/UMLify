<?php
if (isset($_POST['upload_dir'])) {
    $upload_dir = $_POST['upload_dir'];
    $folder_name = basename($upload_dir); // Extrahiere den Ordnername aus dem Pfad
    exec('python python-script/main.py "' . $folder_name . '"');
}
?>