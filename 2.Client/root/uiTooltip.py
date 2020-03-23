## 1.) Modify like this:
class HyperlinkItemToolTip(ItemToolTip):
	def __init__(self):
		ItemToolTip.__init__(self, isPickable=True)

	def SetHyperlinkItem(self, tokens):
		minTokenCount = 3 + player.METIN_SOCKET_MAX_NUM
		if app.ENABLE_CHANGE_LOOK:
			minTokenCount += 1

		maxTokenCount = minTokenCount + 2 * player.ATTRIBUTE_SLOT_MAX_NUM
		if tokens and len(tokens) >= minTokenCount and len(tokens) <= maxTokenCount:
			head, vnum, flag = tokens[:3]
			itemVnum = int(vnum, 16)
			if app.ENABLE_SOCKET_UPDATE:
				metinSlot = [int(metin, 16) for metin in tokens[3:7]]
				rests = tokens[7:]
			else:
				metinSlot = [int(metin, 16) for metin in tokens[3:6]]
				rests = tokens[6:]

			transmutation = 0
			if app.ENABLE_CHANGE_LOOK:
				if app.ENABLE_SOCKET_UPDATE:
					rests = tokens[8:]
					cnv = [int(cnv, 16) for cnv in tokens[7:8]]
					transmutation = int(cnv[0])
				else:
					rests = tokens[7:]
					cnv = [int(cnv, 16) for cnv in tokens[6:7]]
					transmutation = int(cnv[0])

			if rests:
				attrSlot = []
				rests.reverse()
				while rests:
					key = int(rests.pop(), 16)
					if rests:
						val = int(rests.pop())
						attrSlot.append((key, val))

				attrSlot += [(0, 0)] * (player.ATTRIBUTE_SLOT_MAX_NUM - len(attrSlot))
			else:
				attrSlot = [(0, 0)] * player.ATTRIBUTE_SLOT_MAX_NUM

			self.ClearToolTip()

			if app.ENABLE_CHANGE_LOOK:
				if not transmutation:
					self.AddItemData(itemVnum, metinSlot, attrSlot)
				else:
					self.AddItemData(itemVnum, metinSlot, attrSlot, 0, player.INVENTORY, -1, transmutation)
			else:
				self.AddItemData(itemVnum, metinSlot, attrSlot)

			ItemToolTip.OnUpdate(self)

	def OnUpdate(self):
		pass

	def OnMouseLeftButtonDown(self):
		self.Hide()
