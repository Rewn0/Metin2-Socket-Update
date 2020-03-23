/*
Navicat MySQL Data Transfer

Source Server         : Rewn
Source Server Version : 50634
Source Host           : 0.0.0.0
Source Database       : player

Target Server Type    : MYSQL
Target Server Version : 50634
File Encoding         : 65001

Date: 2020-03-23 00:55:35
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for item_proto
-- ----------------------------
DROP TABLE IF EXISTS `item_proto`;
CREATE TABLE `item_proto` (
  `vnum` int(11) unsigned NOT NULL DEFAULT '0',
  `name` varbinary(48) NOT NULL DEFAULT 'Noname',
  `locale_name` varbinary(50) NOT NULL DEFAULT 'Noname',
  `type` tinyint(2) NOT NULL DEFAULT '0',
  `subtype` tinyint(2) NOT NULL DEFAULT '0',
  `weight` int(3) DEFAULT '0',
  `size` tinyint(3) DEFAULT '0',
  `antiflag` int(11) unsigned DEFAULT '0',
  `flag` int(11) unsigned DEFAULT '0',
  `wearflag` int(11) unsigned DEFAULT '0',
  `immuneflag` set('PARA','CURSE','STUN','SLEEP','SLOW','POISON','TERROR') NOT NULL,
  `gold` int(11) DEFAULT '0',
  `shop_buy_price` bigint(255) unsigned NOT NULL DEFAULT '0',
  `refined_vnum` int(10) unsigned NOT NULL DEFAULT '0',
  `refine_set` smallint(11) unsigned NOT NULL DEFAULT '0',
  `refine_set2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `magic_pct` int(4) NOT NULL DEFAULT '0',
  `limittype0` tinyint(4) DEFAULT '0',
  `limitvalue0` int(11) DEFAULT '0',
  `limittype1` tinyint(4) DEFAULT '0',
  `limitvalue1` int(11) DEFAULT '0',
  `applytype0` tinyint(4) DEFAULT '0',
  `applyvalue0` int(11) DEFAULT '0',
  `applytype1` tinyint(4) DEFAULT '0',
  `applyvalue1` int(11) DEFAULT '0',
  `applytype2` tinyint(4) DEFAULT '0',
  `applyvalue2` int(11) DEFAULT '0',
  `value0` int(11) DEFAULT '0',
  `value1` int(11) DEFAULT '0',
  `value2` int(11) DEFAULT '0',
  `value3` int(11) DEFAULT '0',
  `value4` int(11) DEFAULT '0',
  `value5` int(11) DEFAULT '0',
  `socket0` tinyint(4) DEFAULT '-1',
  `socket1` tinyint(4) DEFAULT '-1',
  `socket2` tinyint(4) DEFAULT '-1',
  `socket3` tinyint(4) DEFAULT '-1',
  `specular` tinyint(4) NOT NULL DEFAULT '0',
  `socket_pct` int(4) NOT NULL DEFAULT '0',
  `addon_type` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`vnum`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
