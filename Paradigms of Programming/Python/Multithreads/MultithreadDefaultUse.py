import threading
import time

class MyThread(threading.Thread):
    def __init__(self, threadId, name, delay: int = 1, repeat: int = 1):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.delay = delay
        self.repeat = repeat

    def run(self):
        print('Starting %s' %(self.name))
        printTime(self.name, self.delay, self.repeat)
        print('Ending %s' %(self.name))

def printTime(threadName: str, delay: int = 1, repeat: int = 1):
    for i in range(repeat):
        time.sleep(delay)
        print('> %s: %s' %(threadName, time.ctime()))

def main():
    try:
        a = MyThread(1, 'Thread-1', 1, 5)
        b = MyThread(1, 'Thread-2', 2, 5)
        a.start()
        b.start()
        a.join()
        b.join()
    except:
        print('Error: Unable to start thread.')

if __name__ == '__main__':
    main()
