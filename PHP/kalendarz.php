<?php
// $data = "2022-04-27";
// echo date("w", strtotime($data));
    $db = mysqli_connect('localhost', 'root', '', '3b2');
    
    if(isset($_POST['data'])){
        $data = $_POST['data'];
        $temat = $_POST['temat'];
        $tresc = $_POST['tresc'];
        $q1 = "INSERT INTO `kalendarz`(`data`, `temat`, `tresc`) VALUES ('$data','$temat','$tresc')";
        $r1 = mysqli_query($db, $q1);
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="" method = "post">
        <input type="date" name = "data" id="">
        <input type="text" name="temat" id="">
        <input type="text" name="tresc" id="">
        <input type="submit" value="zatwierdz">
    </form>
    <hr>
    <table>
        <?php
            $q2 = "SELECT * FROM `kalendarz` WHERE `data` >='2022-05-01' AND `data` <= '2022-05-31' ORDER BY `kalendarz`.`data` ASC;";
            $r2 = mysqli_query($db, $q2);
            $licznik = 0;

            if(date("w",strtotime("2022-04-25"))%7 == 0) $data = 7;
            else $data = date("w",strtotime("2022-04-25"))%7;

            echo '<tr>';
            for($i = 0; $i < $data - 1; $i++){
                echo'<td> </td>';
            }
            while($row2 = mysqli_fetch_row($r2))
                echo '<td>
                    '.$row2[1].'<br>
                    <b>'.$row2[2].'</b><br>
                    '.$row2[3].'
                </td>';
                if(date("w",strtotime($row2[1]))%7 == 0) echo '</tr><tr>'
        ?>
        </tr>
    </table>
</body>
</html>
<?php
    mysqli_close($db);
?>