<?php
    $db = mysqli_connect("localhost", "root", "","3b1");
    //print_r($_POST); //testuje program
    if(isset($_POST['imie']))
    {
        $imie = $_POST['imie'];
        $nazwisko = $_POST['nazwisko'];
        $wiek = $_POST['wiek'];
        $q2 = "INSERT INTO `dane`(`imie`, `nazwisko`, `wiek`) VALUES ('$imie','$nazwisko','$wiek');";
        if(mysqli_query($db,$q2)) //to jest żle bo jest przez html
        {
            echo 'zapisano w bazie danych';
        }
        else
        {
            echo 'blad zapisu';
        }
    }
    
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pierwsza lekcja PHP</title>
</head>
<body>

    <form action="#" method="post">
        <input type="text" name="imie" id="" require>
        <input type="text" name="nazwisko" id="" require>
        <input type="number" name="wiek" id="" require>
        <input type="submit" value="Zatwierdz">
    </form>

    <hr>

    <table>
    <?php
        $q1 = "SELECT * FROM `dane`;"; //zapytanie
        $r1 = mysqli_query($db, $q1);
        while($row1 = mysqli_fetch_array($r1)) //działa dopuki mamy wyniki 
        {
            echo '<tr>
                <td>'.$row1[0].'</td>
                <td>'.$row1[1].'</td>
                <td>'.$row1[2].'</td>
                <td>'.$row1[3].'</td>
                </tr>';
                
                /*for($i = 0; $i < 4; $i++)
                echo '<td>'.$row1[$i].'</td>';*/ //możemy też tak
                //foreach($i as $row1) echo '<td>'.$row1[$i].'</td>; //albo tak   
        }
        
    ?>
    </table>

    <?php
        /*$q2 = "SELECT * FROM `dane` WHERE `wiek` BETWEEN '22' AND '35';";
        $r2 = mysqli_query($db, $q2);
        $row2 = mysqli_fetch_row($r2);
    
        while($row2 = mysqli_fetch_array($r2))
        {
            echo 'nazwisko: '.$row2['nazwisko'].' imie: '.$row2['imie'].' wiek: '.$row2['wiek'].'<br>';
        }*/
    ?>

</body>
</html>
<?php
    mysqli_close($db);
?>




<?php

    //aby odświeżyć strone klikamy na pasek url i enter nie f5!!!
    //$db = mysqli_connect("localhost", "root", "","3b1"); //tworzenie połączenia

    /*$q1 = "SELECT * FROM `dane`;"; //zapytanie
    $r1 = mysqli_query($db, $q1);
    $row1 = mysqli_fetch_row($r1);
    print_r($row1);
    $row1 = mysqli_fetch_row($r1);
    print_r($row1);*/

    /*$r1 = mysqli_query($db, $q1);
    while($row1 = mysqli_fetch_array($r1)) //działa dopuki mamy wyniki 
    {
        echo "id: $row1[0] imie: $row1[1] nazwisko: $row1[2] <br>";//nie bedzie dzialac dla ..._assoc tylko dla ..._row
        echo 'nazwisko: '.$row1['nazwisko'].' imie: '.$row1['imie'].'<br>'; //działa dla ..._assoc
        //..._array tworzy 2 tablice: zwykłą i asocjacyjną, dlatego możemy użyć tych 2 metod wyświetlenia
        //wszystkie znacznki html muszą być w apostrofach nie w cudzysłowiach
    }*/

    /*$q2 = "SELECT * FROM `dane` WHERE `wiek` BETWEEN '22' AND '35';";
    $r2 = mysqli_query($db, $q2);
    $row2 = mysqli_fetch_row($r2);

    while($row2 = mysqli_fetch_array($r2))
    {
        echo 'nazwisko: '.$row2['nazwisko'].' imie: '.$row2['imie'].' wiek: '.$row2['wiek'].'<br>';
    }*/

    
    //nie wyswietlamy nic przed stroną (przed znacznikami html)
    //mysqli_close($db); //zamykanie połączenia
?>