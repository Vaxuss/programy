<?php
    $db = mysqli_connect("localhost", "root", "", "egzamin5");
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Mój kalendarz</title>
    <link rel="stylesheet" href="styl5.css">
</head>
<body>
    
<section id = "baner1">

    <img src="logo1.png" alt="logo1">

</section>

<section id = "baner2">

<h1>KALENDARZ</h1>

<?php
    $q1 = "SELECT `miesiac`, `rok` FROM `zadania` WHERE `dataZadania` = '2020-07-01'";
    $r1 = mysqli_query($db, $q1);
    $row1 = mysqli_fetch_row($r1);
    echo "miesiac: ".$row1[0]." rok: ".$row1[1];
?>

</section>

<section id = "main">

<?php
    $q2 = "SELECT `dataZadania`, `wpis` FROM `zadania` WHERE `miesiac` = 'lipiec'";
    $r2 = mysqli_query($db, $q2);
    while($row2 = mysqli_fetch_row($r2)){
        echo "<section id = 'blok'><h5>".$row2[0]."</h5><p>".$row2[1]."</p></section>";
    }
?>

</section>

<section id = "stopka">

    <form action="" method="post">
        Dodaj wpis: <input type="text" name="dodaj" id="dodaj">
        <input type="submit" value="DODAJ">
    </form>

    <p>Stronę wykonał: 0000</p>

    <?php
        if(isset($_POST['dodaj'])){
            $wpis = $_POST['dodaj'];
            $q3 = "UPDATE `zadania` SET `wpis`='$wpis' WHERE `dataZadania` = '2020-07-13'";
            $r3 = mysqli_query($db, $q3);
        }
    ?>
</section>

</body>
</html>

<?php
    mysqli_close($db);
?>