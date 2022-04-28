<?php
if(isset($_COOKIE['font']))
{
    $kolor=$_COOKIE['font'];
}
if(isset($_POST["font"]))
{
    setcookie('font',$_POST["font"],time()+15);
    $kolor=$_POST["font"];
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
    <!-- <form action="" method="post">
        Imie<input type="text" name="imie" id="">
        Nazwisko<input type="text" name="nazwisko" id="">
        <input type="submit" value="Wyślij">
    </form><br> -->
    <form action="" method="post">
    <input type="radio" name="font" value="white">white
    <input type="radio" name="font" value="yellow">yellow
    <input type="radio" name="font" value="green">green
    <input type="submit" value="Wyślij">
    </form>
    <div class="tekst">Spanko</div>
</body>
</html>
<?php

?>