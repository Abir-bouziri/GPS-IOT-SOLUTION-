-- phpMyAdmin SQL Dump
-- version 5.1.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jun 25, 2022 at 02:41 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 7.4.28

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `gps_db`
--

-- --------------------------------------------------------

--
-- Table structure for table `gps`
--

CREATE TABLE `gps` (
  `id` int(6) UNSIGNED NOT NULL,
  `id_véhicule` float NOT NULL,
  `immatricule` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `lattitude` float NOT NULL,
  `longtitude` float DEFAULT NULL,
  `gps_time` time DEFAULT NULL,
  `gps_date` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `gps`
--

INSERT INTO `gps` (`id`, `id_véhicule`, `immatricule`, `lattitude`, `longtitude`, `gps_time`, `gps_date`) VALUES
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:17:51', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.731, 10.2431, '12:19:52', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7308, 10.2432, '12:22:53', '2022-05-17'),
(0, 26, '120_tunis_1230', 37.2746, 9.86272, '12:23:57', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:26:54', '2022-05-17'),
(1, 26, '120_tunis_1230', 37.2746, 9.86272, '12:23:57', '2022-05-17'),
(0, 27, '140_tunis_1470', 35.8256, 10.6084, '12:28:59', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7308, 10.2433, '12:30:55', '2022-05-17'),
(3, 27, '140_tunis_1470', 35.8256, 10.6084, '12:28:59', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:34:56', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7306, 10.2433, '12:36:57', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7308, 10.2432, '12:40:58', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7308, 10.2432, '12:42:59', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:47:00', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2434, '12:50:01', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:54:02', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '12:56:03', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:00:04', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:03:05', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:07:06', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:11:07', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:14:08', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2434, '13:18:09', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:21:10', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:23:11', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2432, '13:27:12', '2022-05-17'),
(0, 25, '220_tunis_2013', 36.7307, 10.2433, '13:29:13', '2022-05-17');
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
