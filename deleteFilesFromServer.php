<?php
$dir_path = 'uploads/';

if (is_dir($dir_path)) {
    $files = scandir($dir_path);
    foreach ($files as $file) {
        unlink($dir_path . $file);
    }
}
?>