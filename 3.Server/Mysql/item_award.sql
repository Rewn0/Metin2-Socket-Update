/*
Navicat MySQL Data Transfer

Source Server         : Rewn
Source Server Version : 50634
Source Host           : 0.0.0.0
Source Database       : player

Target Server Type    : MYSQL
Target Server Version : 50634
File Encoding         : 65001

Date: 2020-03-23 00:55:28
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for item_award
-- ----------------------------
DROP TABLE IF EXISTS `item_award`;
CREATE TABLE `item_award` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `pid` int(10) unsigned NOT NULL DEFAULT '0',
  `login` varchar(16) NOT NULL DEFAULT '' COMMENT 'LOGIN_MAX_LEN=30',
  `vnum` int(6) unsigned NOT NULL DEFAULT '0',
  `count` int(10) unsigned NOT NULL DEFAULT '0',
  `given_time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `taken_time` datetime DEFAULT NULL,
  `item_id` int(11) unsigned DEFAULT NULL,
  `why` varchar(128) DEFAULT NULL,
  `socket0` int(11) unsigned NOT NULL DEFAULT '0',
  `socket1` int(11) unsigned NOT NULL DEFAULT '0',
  `socket2` int(11) unsigned NOT NULL DEFAULT '0',
  `socket3` int(11) unsigned NOT NULL DEFAULT '0',
  `mall` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `pid_idx` (`pid`),
  KEY `given_time_idx` (`given_time`),
  KEY `taken_time_idx` (`taken_time`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
