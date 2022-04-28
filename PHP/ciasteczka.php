<?php
    if(isset($_POST["czas"]))
    {
        $imie=$_POST["imie"];
        $nazw=$_POST["nazwisko"];
        $czas=$_POST["czas"];
        $dane = $imie.' '.$nazw;
        setcookie('dane',$dane,time()+$czas);
    }
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php if(!isset($_COOKIE["dane"])){ ?>
    <form action="" method="post">
        <input type="text" name="imie" id="">
        <input type="text" name="nazwisko" id="">
        <input type="number" name="czas" id="">
        <input type="submit" value="Wyślij">
    </form>
    <?php } else echo "formularz jest już wypełniony!<br>"; if(isset($_COOKIE["dane"])) echo $_COOKIE['dane']; ?>
</body>
</html>