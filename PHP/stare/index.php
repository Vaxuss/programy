<?php
    //print_r($_POST);
    $db = mysqli_connect("localhost", "root", "", "3b1");
    if(isset($_POST['imie'])){
        $imie = $_POST['imie'];
        $nazwisko = $_POST['nazwisko'];
        $q1 = "INSERT INTO `dane`(`imie`, `nazwisko`) VALUES ('$imie','$nazwisko')";
        mysqli_query($db,$q1);
    }
    if(isset ($_GET['usun'])){
        $usun = $_GET['usun'];
        $q3 = "UPDATE `dane` SET `nazwisko` = ' ' WHERE `id` = $usun";
        mysqli_query($db,$q3);

    }
    if(isset ($_POST['naz'])){
        $naz = $_POST['naz'];
        $id = $_POST['id'];
        $q4 = "UPDATE `dane` SET `nazwisko` = '$naz' WHERE `id` = $id";
        mysqli_query($db,$q4);

    }
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
    <form action = "" method = "post">
        <input type = "text" name = "imie" id = "">  
        <input type = "text" name = "nazwisko" id = "">  
        <input type = "submit" value = "Zatwierdz">    
    </form>
    <hr><!--to linia!!!-->
    <?php
        //method = "get"
        //echo $_GET['liczba'];

        // method = "post"
        $q2 = "SELECT * FROM `dane`";
        $r2 = mysqli_query($db,$q2);
        while($row2 = mysqli_fetch_array($r2)){ //mysqli_fetch_row //mysqli_fetch_assoc
            if($row2[2] == ''){
                echo $row2[1].'<form action="" method= "post">
                <input type = "text" name = "naz" id = "">
                <input type = "hidden" name = "id" value = "'.$row2[0].'">
            </form>';
            }else
            echo $row2['imie'].' '.$row2['2'].' <a href = "?usun='.$row2[0].'">usun</a><br>'; //$row2[1] etc. // $row2['imie']
        }
    ?>

</body>
</html>
<?php
    mysqli_close($db)
?>