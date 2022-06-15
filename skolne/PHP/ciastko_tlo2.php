<?php
if(isset($_COOKIE['font']))
{
    $kolor=$_COOKIE['font'];
}
if(isset($_GET["kolo"]))
{
    setcookie('font',$_GET["kolo"],time()+65);
    $kolor=$_GET["kolo"];
}


?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>rejestracja/logowanie</title>
    <style>
        body{
            background-color: <?php echo $kolor;?>;
        }
    </style>
</head>
<body>
    <a href="?kolo=green">green</a><BR>
    <a href="?kolo=purple">purple</a><BR>
    <a href="?kolo=blue">blue</a><BR>
    <a href="?kolo=pink">pink</a><BR>
    <a href="ciastko_tlo2.php">refresh</a><br>
    <a href="ciastko_tlo2_test.php">idz</a>
</body>
</html>
<?php

?>