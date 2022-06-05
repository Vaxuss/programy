-- phpMyAdmin SQL Dump
-- version 5.0.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 05 Cze 2022, 22:10
-- Wersja serwera: 10.4.11-MariaDB
-- Wersja PHP: 7.4.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `fastfood`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `dodatki`
--

CREATE TABLE `dodatki` (
  `id` int(11) NOT NULL,
  `nazwa` varchar(50) NOT NULL,
  `cena` int(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `dodatki`
--

INSERT INTO `dodatki` (`id`, `nazwa`, `cena`) VALUES
(1, 'Małe frytki', 5),
(2, 'Średnie frytki', 8),
(3, 'Duże frytki', 11),
(4, 'Mały shake', 7),
(5, 'Sos czosnkowy', 1),
(6, 'Ketchup', 1),
(7, 'Majonez', 2),
(8, '2 kawałki kurczaka', 4),
(9, '', NULL);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `napoje`
--

CREATE TABLE `napoje` (
  `id` int(11) NOT NULL,
  `nazwa` varchar(50) NOT NULL,
  `cena` int(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `napoje`
--

INSERT INTO `napoje` (`id`, `nazwa`, `cena`) VALUES
(1, 'Puszka Pepsi', 4),
(2, 'Pepsi', 5),
(3, 'Mirynda', 5),
(4, 'Woda', 2),
(6, '', NULL);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `produkt`
--

CREATE TABLE `produkt` (
  `id` int(11) NOT NULL,
  `typ` varchar(50) NOT NULL,
  `nazwa` varchar(100) NOT NULL,
  `cena` int(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `produkt`
--

INSERT INTO `produkt` (`id`, `typ`, `nazwa`, `cena`) VALUES
(1, 'Burger', 'Burger z kurczakiem', 14),
(2, 'Deser', 'Lody z masłem orzechowym', 9),
(3, 'Deser', 'Lody Brownie', 9),
(4, 'Burger', 'Podwójny Burger', 21),
(5, 'Kurczak', '3 kawałki kurczaka', 11),
(6, 'Kurczak', '5 kawałków kurczaka ', 16),
(7, 'Kurczak', '8 kawałków kurczaka ', 20),
(8, 'Wrap ', 'Wrap tahini', 10),
(9, 'Wrap', 'Wrap hawaii', 8),
(10, 'Wrap', 'Wrap duży', 11),
(11, 'Burger', 'Mały burger', 7),
(23, 'Shake', 'Shake truskawkowy', 8),
(24, 'Shake', 'Shake czekoladowy', 8),
(25, 'Shake', 'Shake waniliowy', 8),
(26, 'Shake', 'Shake truskawkowy mały', 6),
(35, 'Burger', 'Cheeseburger', 8),
(37, 'Kurczak', '1 udko', 9),
(39, 'Wrap', 'Wrap Gold', 15),
(40, 'Deser', 'Lody ciastko', 9),
(41, 'Deser', 'Lody ciastko małe', 5),
(42, '', '', 0);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `zamowienie`
--

CREATE TABLE `zamowienie` (
  `id` int(11) NOT NULL,
  `produkt` varchar(100) NOT NULL,
  `napoj` varchar(100) NOT NULL,
  `dodatek` varchar(100) NOT NULL,
  `cena` int(10) NOT NULL,
  `wojewodztwo` varchar(100) DEFAULT NULL,
  `adres` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Zrzut danych tabeli `zamowienie`
--

INSERT INTO `zamowienie` (`id`, `produkt`, `napoj`, `dodatek`, `cena`, `wojewodztwo`, `adres`) VALUES
(51, '8 kawałków kurczaka ', 'Puszka Pepsi', '2 kawałki kurczaka', 0, 'opolskie', 'aaaaaaaaaaaaaaa'),
(52, 'Lody Brownie', 'Woda', 'Sos czosnkowy', 0, 'kujawsko-pomorskie', 'noew'),
(53, 'Lody Brownie', 'Woda', 'Sos czosnkowy', 0, 'kujawsko-pomorskie', 'noew'),
(54, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(55, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(56, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(57, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(58, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(59, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', ''),
(60, 'Burger z kurczakiem', 'Puszka Pepsi', 'Małe frytki', 0, 'dolnoslaskie', '');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `dodatki`
--
ALTER TABLE `dodatki`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `napoje`
--
ALTER TABLE `napoje`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `produkt`
--
ALTER TABLE `produkt`
  ADD PRIMARY KEY (`id`);

--
-- Indeksy dla tabeli `zamowienie`
--
ALTER TABLE `zamowienie`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT dla tabeli `dodatki`
--
ALTER TABLE `dodatki`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- AUTO_INCREMENT dla tabeli `napoje`
--
ALTER TABLE `napoje`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=7;

--
-- AUTO_INCREMENT dla tabeli `produkt`
--
ALTER TABLE `produkt`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=43;

--
-- AUTO_INCREMENT dla tabeli `zamowienie`
--
ALTER TABLE `zamowienie`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=61;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
