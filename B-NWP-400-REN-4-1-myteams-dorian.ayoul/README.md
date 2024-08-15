<h1 align="center">
My_Teams RFC Documentation
</h1>

1. Introduction

```
   This document defines how to use network management protocols
   in the Epitech NWP project My_Teams realized by Xavier Tonnellier
   and Dorian Ayoul (delivered on June 5th 2022).
```

2. Client

```
   The client is able to connect to a server,
   send multiple commands to it,
   receive replies from it and
   display informations to the user.

   The client must send command in a specific format described later and
   should display the reply in a human readable format.

   The client receives replies from the server in a particular format :
   code + arguments.

      {"500\0", &error}
      {"501\0", &unknown_user}
      {"502\0", &unauthorized}
      {"200\0", &help}
      {"207\0", &users}
      {"206\0", &user}
      {"201\0", &login}
      {"202\0", &logout}
      {"203\0", &my_send}
      {"204\0", &messages}
      {"208\0", &subscribe}
      {"209\0", &subscribed}
      {"210\0", &unsubscribe}
      {"211\0", &create}
```

3. Server

```
   The server is able to accept multiple clients,
   send replies to a specific client and
   broadcast a message to multiple clients.

   The server is able to keep data about users and teams.
   Clients with the right permissions are able to access that data.
   The server stores the data so it can be reused after a restart.

   Users are able to create teams, channels and threads.
   They also are able to create replies in threads and send private messages
   to other users.
   All of this information can to be accessed by users
   if they have the right permissions.

   Some events are broadcasted to multiple connected clients,
   please refer to the Reply Codes and Commands sections for more information
   about broadcasted events.

      {"users\0", &users}
      {"user\0", &user}
      {"help\0", &help}
      {"login\0", &login}
      {"logout\0", &logout}
      {"send\0", &my_send}
      {"messages\0", &messages}
      {"subscribe\0", &subscribe}
      {"subscribed\0", &subscribed}
      {"unsubscribe\0", &unsubscribe}
      {"use\0", &use}
      {"create\0", &create}
      {"list\0", &list}
      {"info\0", &info}

      Maximum name length = 32 char
      Maximum descriptions team/channel/thread length = 255 char
      Maximum message length = 512 char
```

4. Command list

```
   help :
       send : "help: <[]>"
       received : "200: <[help_string]>"

   users :
       send : "users: <[]>"
       received : "207: <[ids][names][is_logins]>"
   
   user :
       send : "user: <[id]>"
       received : "206: <[id][name][is_login]>

   login :
       send : "login: <[name]>"
       recevied : "201: <[id][name]>
   
   logout :
       send : "logout: <[]>
       received : "202: <[id][name]>

   send :
       send : "send: <[id][message_body]>
       received : "203: <[id][message_body]>

   messages :
       send : "messages: <[id]>"
       received : "204: <[id][timestamps][message_bodys]>

   subscribe :
       send : "subscribe: <[team_id]>"
       recevied : "208: <[user_id][team_id]>

   unsubscribe :
       send : "subscribe: <[team_id]>"
       recevied : "210: <[user_id][team_id]>

   subscribed :
       send : "subscribed: <?[team_id]>
       received : "209: <[team_ids][team_names][team_descs]>

   create :
       send : "create: <?[id]>
       received "211: <?[id]>

   error :
       received :
          "501: <unknown_user>"
          "502: <unauthorized>"
          "500: <other error>"
```
