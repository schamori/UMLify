<?php 
session_start();
$logged_in = isset($_SESSION["id"]);
$isAdmin = (@$_SESSION["username"] == 'admin');
?>
<nav class="navbar navbar-expand-md navbar-light bg-light">
    <a class="navbar-brand" href="index.php">Logo</a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
        <span class="navbar-toggler-icon"></span>
    </button>
    <div class="collapse navbar-collapse" id="navbarNav">
        <ul class="navbar-nav mr-auto">
            <li class="nav-item">
                <a class="nav-link" href="index.php">Diagramm erstellen</a>
            </li>
        </ul>
        <ul class="navbar-nav ml-auto">
        <?php 
          if ($logged_in){
            if($isAdmin){
                ?>
                <li class="nav-item">
                <a class="nav-link" href="showAllUMLs.php">Alle UMLs</a>
            </li>
            <?php
            }
            ?>
            <li class="nav-item">
                <a class="nav-link" href="history.php">Ihr Verlauf: <?php echo $_SESSION["username"]?></a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="logout.php">Abmelden</a>
            </li>
            <?php } else{ ?>
            <li class="nav-item">
                <a class="nav-link" href="login.php">Anmelden</a>
            </li>
            <li class="nav-item">
                <a class="nav-link" href="register.php">Registrieren</a>
            </li>
            <?php } ?>
        </ul>
    </div>
</nav>
