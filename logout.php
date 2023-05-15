<?php
include 'top_navbar.php';
session_destroy();
header('Location: index.php');
?>