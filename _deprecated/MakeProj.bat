cd src

g++ -c -I../include -o../bin/material.o material.cpp
g++ -c -I../include -o../bin/abstraction.o abstraction.cpp
g++ -c -I../include -o../bin/sprite.o sprite.cpp
g++ -c -I../include -o../bin/texture.o texture.cpp
g++ -c -I../include -o../bin/transform.o transform.cpp
g++ -c -I../include -o../bin/entity.o entity.cpp
g++ -c -I../include -o../bin/tree.o tree.cpp
g++ -c -I../include -o../bin/root.o root.cpp
g++ -c -I../include -o../bin/component.o component.cpp
g++ -c -I../include -o../bin/instance.o instance.cpp
g++ -c -I../include -o../bin/camera.o camera.cpp
g++ -c -I../include -o../bin/util.o util.cpp


cd ..

cd bin

ar rvs ../lib/libGLEWY.a material.o abstraction.o sprite.o texture.o transform.o entity.o tree.o root.o component.o instance.o camera.o util.o

cd ..