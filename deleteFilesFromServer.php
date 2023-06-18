<?php
$dir_path = 'uploads/';

if (is_dir($dir_path)) {
    deleteSubdirectories($dir_path);
}

function deleteSubdirectories($dir) {
    if (!is_dir($dir)) {
        return;
    }

    $subdirectories = glob($dir . '/*', GLOB_ONLYDIR);
    foreach ($subdirectories as $subdirectory) {
        deleteDirectory($subdirectory);
    }
}

function deleteDirectory($dir) {
    $files = array_diff(scandir($dir), array('.', '..'));
    foreach ($files as $file) {
        $file_path = $dir . '/' . $file;
        if (is_dir($file_path)) {
            deleteDirectory($file_path);
        } else {
            unlink($file_path);
        }
    }

    rmdir($dir);
}
?>
