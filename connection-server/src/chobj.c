/*
 * In The Name Of God
 * ========================================
 * [] File Name : chobj.c
 *
 * [] Creation Date : 26-01-2015
 *
 * [] Last Modified : Wed Jan 28 15:27:27 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <glib.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>

#include "chobj.h"
#include "sockets.h"

struct chobj *chobj_new(const char *id, int socket,
		struct sockaddr_in addr)
{
	struct chobj *new = g_new(struct chobj, 1);

	new->child = NULL;
	new->fd = socket;
	strcpy(new->id, id);
	new->client_addr = addr;

	add_socket(&new->fd);

	return new;
}

void chobj_del(struct chobj *chobj)
{
	g_slist_free(chobj->child);
	free(chobj);
}

void chobj_add_child(struct chobj *parent,
		struct chobj *child)
{
	parent->child = g_slist_append(parent->child, child);
}

void chobj_del_child(struct chobj *parent,
		struct chobj *child)
{

}
