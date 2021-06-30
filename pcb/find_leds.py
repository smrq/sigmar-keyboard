import pcbnew

board = pcbnew.GetBoard()

indices = range(52, 58+1) + range(32, 27-1, -1) + range(33, 39+1) + range(45, 40-1, -1) + range(46, 51+1)
leds = [board.FindModuleByReference('D%d' % i) for i in indices]
min_x = min([led.GetPosition().x for led in leds])
max_x = max([led.GetPosition().x for led in leds])
min_y = min([led.GetPosition().y for led in leds])
max_y = max([led.GetPosition().y for led in leds])

for led in leds:
	pos = led.GetPosition();
	scaled_x = 112 * (pos.x - min_x) / (max_x - min_x)
	scaled_y = 64 * (pos.y - min_y) / (max_y - min_y)
	print('%s: { %d, %d } { %d, %d }' % (led.GetReference(), scaled_x, scaled_y, 224-scaled_x, scaled_y))

# exec(open('find_leds.py').read())
