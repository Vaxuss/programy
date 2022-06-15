<?php
    $db = mysqli_connect("localhost", "root", "","3b1");
    if(isset($_POST['imie']))
    {
        $imie = $_POST['imie'];
        $nazwisko = $_POST['nazwisko'];
        $q2 = "INSERT INTO `dane`(`imie`, `nazwisko`) VALUES ('$imie','$nazwisko');";
        if(mysqli_query($db,$q2)) //to jest żle bo jest przez html
        {
            echo 'zapisano dane';
        }
        else
        {
            echo 'blad zapisu danych';
        }
    }

    if(isset($_POST['ulica']))
    {
        $id = $_POST['osoba'];
        $ulica = $_POST['ulica'];
        $miasto = $_POST['miasto'];
        $kod = $_POST['kod'];
        $q4 = "INSERT INTO `adresy`(`ulica`, `miasto`, `kod`, `id_`) 
        VALUES ('$ulica','$miasto','$kod','$id')";
        if(mysqli_query($db,$q4)) //to jest żle bo jest przez html
        {
            echo 'zapisano dane';
        }
        else
        {
            echo 'blad zapisu danych';
        }
    }
    
?>

<!DOCTYPE html>

<html lang="pl">
    
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Druga lekcja PHP</title>
</head>

<body>

    <form action="#" method="post">
        <input type="text" name="imie" id="" require>
        <input type="text" name="nazwisko" id="" require>
        <input type="submit" value="Zatwierdz">
    </form>

    <hr>

    <form action="#" method="post">
        <select name = "osoba" id="">
            <?php
            $q3 = "SELECT * FROM `dane`;";
            $r3 = mysqli_query($db,$q3);
            while($row3 = mysqli_fetch_row($r3))
            {
                $q6 = "SELECT `id` FROM `adresy` WHERE `id_` = $row3[0]";
                $r6 = mysqli_query($db,$q6);
                if(!mysqli_fetch_row($r6))
                    echo '<option value="'.$row3[0].'">'.$row3[1].' '.$row3[2].'</option>';
            }
            ?>
        </select>
        <input type="text" name="ulica" id="">
        <input type="text" name="miasto" id="">
        <input type="text" name="kod" id="">
        <input type="submit" value="Zatwierdz">
    </form>

    <hr>
    

    <table>
    <?php
        $q5 = "SELECT dane.id , imie, nazwisko , adresy.ulica , adresy.miasto , adresy.kod FROM `dane` LEFT JOIN adresy ON dane.id = adresy.id_;";
        $r5 = mysqli_query($db, $q5);
        while($row5 = mysqli_fetch_array($r5)) 
        {
            echo '<tr>
                <td>'.$row5[0].'</td>
                <td>'.$row5[1].'</td>
                <td>'.$row5[2].'</td>
                <td>'.$row5[3].'</td>
                <td>'.$row5[4].'</td>
                <td>'.$row5[5].'</td>
                </tr>';
                
        }
        
    ?>
    </table>
</body>

</html>

<?php
    mysqli_close($db);
?>
