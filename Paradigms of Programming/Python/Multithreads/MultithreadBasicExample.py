import threading

# Function to be handled for the thread
def printIteration(threadName, repeat):
    for i in range(repeat):
        print('> %s - Iteration: %d' %(threadName, i + 1))

def main():
    try:
        a = threading.Thread(target=printIteration, args=('Thread-1', 7))
        a.start()
        b = threading.Thread(target=printIteration, args=('Thread-2', 5))
        b.start()
    except:
        print('Error: Unable to start thread.')

if __name__ == '__main__':
    main()