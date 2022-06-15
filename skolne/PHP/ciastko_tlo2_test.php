<?php
if(isset($_COOKIE['font']))
{
    $kolor=$_COOKIE['font'];
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        body{
            background-color: <?php echo $kolor;?>;
        }
    </style>
</head>
<body>
    <a href="ciastko_tlo2.php">wroc</a>
</body>
</html>