<?php
    $db = mysqli_connect("localhost", "root", "", "fastfood");
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <link rel = "stylesheet" href = "css.css">
    <title>FTC - Zamów</title>

    <script>
        function toHref(web){
            window.location.href = web;
        }
    </script>
</head>
<body>
    <div id = "top" onclick="toHref('main.html')" >
        <h1>Fried Texas Chicken</h1>
    </div>
<!--To wygląda jakby mi się budżet skończył-->
    <div id = "formorder">
        <div id = "baner" >
            <h2><b>PORA ZAMAWIAĆ!</b></h2>
        </div>
        <div id = "formularz">
        <form id = "zamowienie" method="POST" action="">
            Województwo: <select name="woj" id="woj" style = "font-size:20px">
                <option value="dolnoslaskie">Dolnośląskie</option>
                <option value="kujawsko-pomorskie">Kujawsko-pomorskie</option>
                <option value="lubelskie">Lubelskie</option>
                <option value="lubuskie">Lubuskie</option>
                <option value="lodzkie">Łódzkie</option>
                <option value="malopolskie">Małopolskie</option>
                <option value="mazowieckie">Mazowieckie</option>
                <option value="opolskie">Opolskie</option>
                <option value="podkarpackie">Podkarpackie</option>
                <option value="podlaskie">Podlaskie</option>
                <option value="pomorskie">Pomorskie</option>
                <option value="slaskie">Śląskie</option>
                <option value="swietokrzyskie">Świętokrzyskie</option>
                <option value="warminsko-mazurskie">Warmińsko-mazurskie</option>
                <option value="wielkopolskie">Wielkopolskie</option>
                <option value="zachodniopomorskie">Zachodniopomorskie</option>
            </select><br/><br/>

            Adres: <input type= "text" name = "adres" style = "font-size:16px"><br/><br/>

            Produkt: <select name="produkt" id="produkt" style = "font-size:20px">
            <?php
                $q1 = "SELECT `nazwa`, `cena` FROM `produkt`";
                $r1 = mysqli_query($db,$q1);
                while($row1 = mysqli_fetch_array($r1)){ 
                    if($row1['cena'] != NULL && $row1['cena'] != 0){
                        echo '<option value = "'.$row1['nazwa'].'">'.$row1['nazwa'].' '.$row1['cena'].'zł</option>';
                    }
                    else{
                        echo '<option value = "'.$row1['nazwa'].'">'.$row1['nazwa'].'</option>';
                    }
                }
            ?>
            </select><br/><br/>
            Napoj: <select name="napoj" id="napoj" style = "font-size:20px">
            <?php
                $q2 = "SELECT `nazwa`, `cena` FROM `napoje`";
                $r2 = mysqli_query($db,$q2);
                while($row2 = mysqli_fetch_array($r2)){ 
                    if($row2['cena'] != NULL){
                        echo '<option value = "'.$row2['nazwa'].'">'.$row2['nazwa'].' '.$row2['cena'].'zł</option>';
                    }
                    else{
                        echo '<option value = "'.$row2['nazwa'].'">'.$row2['nazwa'].' '.$row2['cena'].'</option>';
                    }
                }
            ?>
            </select><br/><br/>
            Dodatek: <select name="dodatek" id="dodatek">
            <?php
                $q3 = "SELECT `nazwa`, `cena` FROM `dodatki`";
                $r3 = mysqli_query($db,$q3);
                while($row3 = mysqli_fetch_array($r3)){ 
                    if($row3['cena'] != NULL){
                        echo '<option value = "'.$row3['nazwa'].'">'.$row3['nazwa'].' '.$row3['cena'].'zł</option>';
                    }
                    else{
                        echo '<option value = "'.$row3['nazwa'].'">'.$row3['nazwa'].' '.$row3['cena'].'</option>';
                    }
                }
            ?>
            </select>
            <br/><br/><input type="submit" name="submit" value="Zamawiamy!" id = "submit">
            <?php
               if(isset($_POST['submit'])){
                $woj = $_POST['woj'];
                $produkt = $_POST['produkt'];
                $napoj = $_POST['napoj'];
                $dodatek = $_POST['dodatek'];
                $adres = $_POST['adres'];

                $q4 = "INSERT INTO `zamowienie`(`produkt`, `napoj`, `dodatek`, `wojewodztwo`, `adres`) VALUES ('$produkt','$napoj','$dodatek','$woj','$adres')";
                $r4 = mysqli_query($db, $q4);
                $cena = "SELECT `produkt.cena` FROM `zamowienie` JOIN `produkt` ON `zamowinie.produkt` = `produkt.nazwa` WHERE `produkt` = `produkt.nazwa`";
                $q5 = "UPDATE `zamowienie` SET `cena` VALUES('$cena') WHERE `id`=(SELECT MAX(`id`) FROM `zamowienie`)";
                $r5 = mysqli_query($db, $q5);
            }
            ?>
        </form>
        </div>
    </div>

    <footer>
        <div><img src ="phone.svg" height=5% width=5%><br/>
        <b>Zamów przez telefon<br/>
            069 420 069</b></div> 
    </footer>  
</body>
</html>

<?php
    $db = mysqli_close($db);
?>