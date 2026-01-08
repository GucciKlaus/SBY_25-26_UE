import socket
import threading
class WorkerThread ( threading.Thread ):
    def __init__ ( self , socket ):
        threading.Thread.__init__ ( self )
        self.socket = socket
    def run ( self ):
        self.socket.send ( " Welcome ␣ to ␣ SBY1 \n " . encode('utf-8'))

serversocket = socket.socket ( socket.AF_INET , socket.SOCK_STREAM )
serversocket.bind (( "0.0.0.0" ,31337))
serversocket.listen ()
while True :
    ( clientsocket ,( ip , port )) = serversocket.accept ()
    print ( " New ␣ connection ␣ from ␣ {}:{} " . format ( ip , port ))
    workerthread = WorkerThread ( clientsocket )
    workerthread.start ()