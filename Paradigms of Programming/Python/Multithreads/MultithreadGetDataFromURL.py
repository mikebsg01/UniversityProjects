import threading
import requests

class MyThread(threading.Thread):
    def __init__(self, threadId, name, worker, data):
        threading.Thread.__init__(self)
        self.threadId = threadId
        self.name = name
        self.worker = worker
        self.data = data

    def run(self):
        print('\n> Starting %s...' %(self.name))
        self.worker(self.name, self.data)
        print('\n> Exiting %s.' %(self.name))

def writeInFile(txt: str):
    userDataFile = open('test/users.txt', 'r')
    addComma = userDataFile.read() != ''
    userDataFile.close()

    userDataFile = open('test/users.txt', 'a')
    userDataFile.write('%s\n%s' %(',' if addComma else '', txt))
    userDataFile.close()

def workerGetDataFromURL(threadName, url: str):
    print('\n>> %s: Getting data from URL <%s>' %(threadName, url))
    userData = requests.get(url)
    writeInFile(userData.text)
    print('\n>> %s - JSON Data:\n\n%s' %(threadName, userData.json()))

def main():
    users = [1, 2, 7]
    threadId = 1

    for userId in users:
        threadName = 'Thread-{}'.format(threadId)
        url = 'https://jsonplaceholder.typicode.com/users/{}'.format(userId)

        try:
            t = MyThread(threadId, threadName, workerGetDataFromURL, url)
            t.start()
            t.join()
        except:
            print('Error: Unable to start thread with ID: {}.'.format(threadId))

        threadId += 1

if __name__ == '__main__':
    main()
