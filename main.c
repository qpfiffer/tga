// vim: noet ts=4 sw=4
#include <string.h>
#include <time.h>

#include <38-moths/38-moths.h>

int main_sock_fd;

/*
 * ---------------------
 * C O M I N G  S O O N
 * ---------------------
 */

static int index_handler(const http_request *request, http_response *response) {
	greshunkel_ctext *ctext = gshkl_init_context();
	return render_file(ctext, "./index.html", response);
}

static const route all_routes[] = {
	{"GET", "root_handler", "^/$", 0, &index_handler, &heap_cleanup},
};

int main(int argc, char *argv[]) {
	http_serve(&main_sock_fd, 8080, 2, all_routes, sizeof(all_routes)/sizeof(all_routes[0]));
	return 0;
}
