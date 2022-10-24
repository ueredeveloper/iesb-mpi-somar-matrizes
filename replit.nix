{ pkgs }: {
	deps = [
		pkgs.sudo
  pkgs.twelf
  pkgs.mpi
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}