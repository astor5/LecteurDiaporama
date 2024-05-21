-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Hôte : mysql-5.7
-- Généré le : mar. 21 mai 2024 à 07:05
-- Version du serveur : 5.7.28
-- Version de PHP : 8.0.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `nodenot_bd9`
--

-- --------------------------------------------------------

--
-- Structure de la table `Diaporamas`
--

CREATE TABLE `Diaporamas` (
  `idDiaporama` int(11) NOT NULL,
  `titre Diaporama` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT '',
  `vitesseDefilement` int(3) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `Diaporamas`
--

INSERT INTO `Diaporamas` (`idDiaporama`, `titre Diaporama`, `vitesseDefilement`) VALUES
(1, 'diapoama Pantxika', 1),
(2, 'diaporama Thierry', 2),
(3, 'diaporama Yann', 1),
(4, 'diaporam Manu', 3);

-- --------------------------------------------------------

--
-- Structure de la table `Diapos`
--

CREATE TABLE `Diapos` (
  `idphoto` int(10) NOT NULL,
  `titrePhoto` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT '',
  `idFam` int(10) NOT NULL DEFAULT '0',
  `uriPhoto` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `Diapos`
--

INSERT INTO `Diapos` (`idphoto`, `titrePhoto`, `idFam`, `uriPhoto`) VALUES
(1, 'Disney_0.gif', 2, '/cartesDisney/Disney_0.gif'),
(2, 'Disney_1.gif', 3, '/cartesDisney/Disney_1.gif'),
(3, 'Disney_2.gif', 1, '/cartesDisney/Disney_2.gif'),
(4, 'Disney_3.gif', 3, '/cartesDisney/Disney_3.gif'),
(5, 'Disney_4.gif', 1, '/cartesDisney/Disney_4.gif'),
(6, 'Disney_5.gif', 3, '/cartesDisney/Disney_5.gif'),
(7, 'Disney_6.gif', 3, '/cartesDisney/Disney_6.gif'),
(8, 'Disney_7.gif', 1, '/cartesDisney/Disney_7.gif'),
(9, 'Disney_8.gif', 3, '/cartesDisney/Disney_8.gif'),
(10, 'Disney_9.gif', 3, '/cartesDisney/Disney_9.gif'),
(11, 'Disney_10.gif', 3, '/cartesDisney/Disney_10.gif'),
(12, 'Disney_11.gif', 3, '/cartesDisney/Disney_11.gif'),
(13, 'Disney_12.gif', 3, '/cartesDisney/Disney_12.gif'),
(14, 'Disney_13.gif', 3, '/cartesDisney/Disney_13.gif'),
(15, 'Disney_14.gif', 3, '/cartesDisney/Disney_14.gif'),
(16, 'Disney_15.gif', 3, '/cartesDisney/Disney_15.gif'),
(17, 'Disney_16.gif', 3, '/cartesDisney/Disney_16.gif'),
(18, 'Disney_17.gif', 3, '/cartesDisney/Disney_17.gif'),
(19, 'Disney_18.gif', 3, '/cartesDisney/Disney_18.gif'),
(20, 'Disney_19.gif', 3, '/cartesDisney/Disney_19.gif'),
(21, 'Disney_20.gif', 3, '/cartesDisney/Disney_20.gif'),
(22, 'Disney_21.gif', 1, '/cartesDisney/Disney_21.gif'),
(23, 'Disney_22.gif', 3, '/cartesDisney/Disney_22.gif'),
(24, 'Disney_23.gif', 3, '/cartesDisney/Disney_23.gif'),
(25, 'Disney_24.gif', 1, '/cartesDisney/Disney_24.gif'),
(26, 'Disney_25.gif', 3, '/cartesDisney/Disney_25.gif'),
(27, 'Disney_26.gif', 3, '/cartesDisney/Disney_26.gif'),
(28, 'Disney_27.gif', 3, '/cartesDisney/Disney_27.gif'),
(29, 'Disney_28.gif', 3, '/cartesDisney/Disney_28.gif'),
(30, 'Disney_29.gif', 1, '/cartesDisney/Disney_29.gif'),
(31, 'Disney_30.gif', 3, '/cartesDisney/Disney_30.gif'),
(32, 'Disney_31.gif', 3, '/cartesDisney/Disney_31.gif'),
(33, 'Disney_32.gif', 3, '/cartesDisney/Disney_32.gif'),
(34, 'Disney_33.gif', 3, '/cartesDisney/Disney_33.gif'),
(35, 'Disney_34.gif', 3, '/cartesDisney/Disney_34.gif'),
(36, 'Disney_35.gif', 3, '/cartesDisney/Disney_35.gif'),
(37, 'Disney_36.gif', 1, '/cartesDisney/Disney_36.gif'),
(38, 'Disney_37.gif', 3, '/cartesDisney/Disney_37.gif'),
(39, 'Disney_38.gif', 1, '/cartesDisney/Disney_38.gif'),
(40, 'Disney_39.gif', 3, '/cartesDisney/Disney_39.gif'),
(41, 'Disney_40.gif', 3, '/cartesDisney/Disney_40.gif'),
(42, 'Disney_41.gif', 1, '/cartesDisney/Disney_41.gif'),
(43, 'Disney_42.gif', 1, '/cartesDisney/Disney_42.gif'),
(44, 'Disney_43.gif', 3, '/cartesDisney/Disney_43.gif'),
(45, 'Disney_44.gif', 1, '/cartesDisney/Disney_44.gif'),
(46, 'Disney_45.gif', 1, '/cartesDisney/Disney_45.gif'),
(47, 'Disney_46.gif', 1, '/cartesDisney/Disney_46.gif'),
(48, 'Disney_47.gif', 1, '/cartesDisney/Disney_47.gif'),
(49, 'Disney_48.gif', 1, '/cartesDisney/Disney_48.gif'),
(50, 'Disney_49.gif', 1, '/cartesDisney/Disney_49.gif'),
(51, 'Disney_50.gif', 1, '/cartesDisney/Disney_50.gif'),
(52, 'Disney_51.gif', 1, '/cartesDisney/Disney_51.gif'),
(53, 'Disney_52.gif', 1, '/cartesDisney/Disney_52.gif'),
(54, 'Disney_53.gif', 1, '/cartesDisney/Disney_53.gif');

-- --------------------------------------------------------

--
-- Structure de la table `DiaposDansDiaporama`
--

CREATE TABLE `DiaposDansDiaporama` (
  `idDiapo` int(10) NOT NULL,
  `idDiaporama` int(10) NOT NULL,
  `rang` smallint(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `DiaposDansDiaporama`
--

INSERT INTO `DiaposDansDiaporama` (`idDiapo`, `idDiaporama`, `rang`) VALUES
(1, 1, 1),
(1, 2, 1),
(2, 3, 1),
(3, 2, 9),
(4, 2, 8),
(5, 1, 7),
(6, 2, 3),
(7, 1, 6),
(8, 1, 20),
(9, 2, 2),
(10, 4, 1),
(11, 3, 7),
(12, 1, 8),
(12, 2, 19),
(13, 1, 5),
(13, 3, 2),
(14, 1, 19),
(15, 2, 18),
(19, 2, 15),
(20, 1, 4),
(21, 4, 9),
(22, 2, 7),
(23, 1, 13),
(24, 1, 3),
(25, 2, 14),
(25, 4, 8),
(26, 1, 2),
(26, 2, 5),
(27, 2, 13),
(28, 3, 8),
(29, 3, 10),
(30, 4, 10),
(31, 2, 12),
(32, 2, 4),
(33, 3, 9),
(33, 4, 7),
(34, 4, 5),
(35, 1, 11),
(36, 1, 12),
(37, 3, 4),
(38, 2, 6),
(38, 4, 6),
(39, 1, 9),
(40, 1, 16),
(40, 2, 11),
(41, 1, 10),
(41, 2, 10),
(42, 1, 14),
(42, 2, 17),
(43, 1, 18),
(43, 3, 3),
(44, 1, 15),
(45, 1, 17),
(46, 2, 16),
(47, 4, 3),
(50, 3, 6),
(50, 4, 4),
(51, 3, 5),
(52, 4, 2),
(54, 4, 11);

-- --------------------------------------------------------

--
-- Structure de la table `Familles`
--

CREATE TABLE `Familles` (
  `idFamille` int(10) NOT NULL,
  `nomFamille` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Déchargement des données de la table `Familles`
--

INSERT INTO `Familles` (`idFamille`, `nomFamille`) VALUES
(1, 'Personnage'),
(2, 'Objet'),
(3, 'Animal');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Diaporamas`
--
ALTER TABLE `Diaporamas`
  ADD PRIMARY KEY (`idDiaporama`);

--
-- Index pour la table `Diapos`
--
ALTER TABLE `Diapos`
  ADD PRIMARY KEY (`idphoto`),
  ADD KEY `idFam` (`idFam`);

--
-- Index pour la table `DiaposDansDiaporama`
--
ALTER TABLE `DiaposDansDiaporama`
  ADD PRIMARY KEY (`idDiapo`,`idDiaporama`),
  ADD KEY `idDiaporama` (`idDiaporama`);

--
-- Index pour la table `Familles`
--
ALTER TABLE `Familles`
  ADD PRIMARY KEY (`idFamille`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Diaporamas`
--
ALTER TABLE `Diaporamas`
  MODIFY `idDiaporama` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;

--
-- AUTO_INCREMENT pour la table `Diapos`
--
ALTER TABLE `Diapos`
  MODIFY `idphoto` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=55;

--
-- AUTO_INCREMENT pour la table `Familles`
--
ALTER TABLE `Familles`
  MODIFY `idFamille` int(10) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Contraintes pour les tables déchargées
--

--
-- Contraintes pour la table `Diapos`
--
ALTER TABLE `Diapos`
  ADD CONSTRAINT `Diapos_ibfk_1` FOREIGN KEY (`idFam`) REFERENCES `Familles` (`idFamille`);

--
-- Contraintes pour la table `DiaposDansDiaporama`
--
ALTER TABLE `DiaposDansDiaporama`
  ADD CONSTRAINT `DiaposDansDiaporama_ibfk_1` FOREIGN KEY (`idDiaporama`) REFERENCES `Diaporamas` (`idDiaporama`),
  ADD CONSTRAINT `DiaposDansDiaporama_ibfk_2` FOREIGN KEY (`idDiapo`) REFERENCES `Diapos` (`idphoto`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
