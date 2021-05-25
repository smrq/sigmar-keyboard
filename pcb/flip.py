import pcbnew

board = pcbnew.GetBoard()
center = board.GetGridOrigin()

for f in board.GetModules():
	if f.IsSelected():
		print('Module ref=%s' % (f.GetReference()))
		pos = f.GetPosition()
		f.SetPosition(pcbnew.wxPoint(2*center.x - pos.x, pos.y))

for t in board.GetTracks():
	if t.IsSelected():
		print('Track cl=%s net=%s' % (t.GetClass(), t.GetNetname()))
		start = t.GetStart()
		end = t.GetEnd()
		t.SetStart(pcbnew.wxPoint(2*center.x - start.x, start.y))
		t.SetEnd(pcbnew.wxPoint(2*center.x - end.x, end.y))

# exec(open('flip.py').read())