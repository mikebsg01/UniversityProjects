import threading
import random
import time

class MyThread(threading.Thread):
    def __init__(self, threadId, name, worker, data):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.worker = worker
        self.data = data

    def run(self):
        print('> Starting %s...' %(self.name))
        self.worker(self.name, self.data)
        print('> Exiting %s.' %(self.name))

cube = lambda x: x ** 3
square = lambda x: x ** 2

def sumAll(threadName: str, data: list = []):
    s = sum(data)
    print('>> %s - Result: %d' %(threadName, s))

def squareSum(threadName: str, data: list = []):
    s = sum(list(map(square, data)))
    print('>> %s - Result: %d' %(threadName, s))

def cubeSum(threadName: str, data: list = []):
    s = sum(list(map(cube, data)))
    print('>> %s - Result: %d' %(threadName, s))

def main():
    N = 1000000 # Number quantity
    nums = [i for i in range(1, N + 1)] # Numbers from 1 to N
    workers = [sumAll, squareSum, cubeSum]
    id = 1

    for worker in workers:
        threadName = 'Thread-{}'.format(id)

        try:
            t = MyThread(id, threadName, worker, nums)
            t.start()
        except:
            print('Error: Unable to start thread.')
        
        id += 1

if __name__ == '__main__':
    main()
