rm main.o
rm main
g++ -g IAPI.h -c
g++ -g WethearAPI.h -c
g++ -g CurlManager.h -c
g++ -g JsonManager.h -c
g++ -g   main.cpp -c
g++ -g -o main main.o  -lcurl -ljsoncpp