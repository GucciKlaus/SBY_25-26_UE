klaus@echo:~/Desktop/FOO$ ls -la /dev/s
shm/      snapshot  snd/      stderr    stdin     stdout    
klaus@echo:~/Desktop/FOO$ ls -la /dev/shm
total 0
drwxrwxrwt  2 root root   40 Nov 24 15:33 .
drwxr-xr-x 22 root root 5540 Nov 24 14:43 ..
klaus@echo:~/Desktop/FOO$ fallocate -l 4K /dev/shm/newsharedmemory
klaus@echo:~/Desktop/FOO$ ls -la /dev/shm
total 4
drwxrwxrwt  2 root  root    60 Nov 24 15:35 .
drwxr-xr-x 22 root  root  5540 Nov 24 14:43 ..
-rw-rw-r--  1 klaus klaus 4096 Nov 24 15:35 newsharedmemory
klaus@echo:~/Desktop/FOO$ echo "Hallo Welt" | dd of=/dev/shm/newsharedmemory 
0+1 records in
0+1 records out
11 bytes copied, 8.7697e-05 s, 125 kB/s
klaus@echo:~/Desktop/FOO$ cat /dev/shm/newsharedmemory 
Hallo Welt
klaus@echo:~/Desktop/FOO$ 

