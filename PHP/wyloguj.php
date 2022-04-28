<?php
    session_start();
    $_SESSION = array();
    session_destroy();
    if(!isset($_SESSION['id'])){
        echo 'zostałeś wylogowany';
        header("refresh:5;url=panel.php");
    } 
?>