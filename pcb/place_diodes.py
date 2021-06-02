import pcbnew

board = pcbnew.GetBoard()

i = 1
j = 27
while i < 25:
	if i == 20:
		i = i + 1
		continue

	switch = board.FindModuleByReference('SW%d' % i)
	diode = board.FindModuleByReference('D%d' % i)
	led = board.FindModuleByReference('D%d' % j)

	pos = switch.GetPosition();

	print('Placing %s and %s relative to %s' % (diode.GetReference(), led.GetReference(), switch.GetReference()))

	diode.SetPosition(pcbnew.wxPoint(pos.x + 4286250, pos.y + 8096250))
	diode.SetOrientation(0)

	led.SetPosition(pcbnew.wxPoint(pos.x, pos.y - 5050000))
	led.SetOrientation(0)

	i = i + 1
	j = j + 1

# exec(open('place_diodes.py').read())