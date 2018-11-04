import spidev
import time
spi = spidev.SpiDev()
spi.open(0,0)
spi.max_speed_hz=3500000
spi.mode=0b01
RANGE = 1000000
data = []
start = time.time()
for i in range(RANGE):
    d = spi.readbytes(2)
    v = d[0]*256+d[1]
#    print '0x{:04x}'.format(v)
#    print 'b{0:16b}'.format(v)
#    print 'b{0:8b}'.format( (v/4)%256 )
    data.append(chr((v/4)%256))
stop = time.time()
spi.close()

with open('entropy.txt', 'wb') as w:
    for i in range(RANGE):
#    print(data[i])
        w.write(data[i])

print '{} Bps'.format(RANGE/(stop-start))