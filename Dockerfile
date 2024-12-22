FROM archlinux:latest

WORKDIR /mnt

RUN pacman -Syyu --noconfirm --disable-sandbox base-devel scons mingw-w64-gcc

CMD [ "bash" ]