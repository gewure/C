/* 
This code uses the Shlemiel the painter’s algorithm. Who is Shlemiel? He’s the guy in this joke:

Shlemiel gets a job as a street painter, painting the dotted lines down the middle of the road. 
On the first day he takes a can of paint out to the road and finishes 300 yards of the road. 
“That’s pretty good!” says his boss, “you’re a fast worker!” and pays him a kopeck.

The next day Shlemiel only gets 150 yards done. “Well, that’s not nearly as good as yesterday, but you’re still a fast worker.
150 yards is respectable,” and pays him a kopeck.

The next day Shlemiel paints 30 yards of the road. 
“Only 30!” shouts his boss. “That’s unacceptable! On the first day you did ten times that much work! What’s going on?”

“I can’t help it,” says Shlemiel. “Every day I get farther and farther away from the paint can!”

 - Copyright belonging to Joel Spolsky (thought he probably is happy about having this shared)
 
 TRY IT ONLINE: https://onlinegdb.com/S11aCBAuI
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void paint (char *str);
long long timeInNanos (void);

int
main (int argc, char *args[])
{

  char *street;
  int days;

  printf ("how long shall Shlemiel paint? ");
  scanf ("%d", &days);

  street = malloc (sizeof (char) * 2 * days);
  for (int i = 0; i < days; i++)
    {
      paint (street);
      printf ("\nday %d ", i);
    }
  free (street);
}

void
paint (char *street)
{
  long long now = timeInNanos ();
  strcat (street, "#");
  printf ("it took Shlemiel %d nanos to paint, Enter to continue?\n",
	  timeInNanos () - now);
  printf ("%s", street);
  char ch;
  scanf ("%c", &ch);		//get something to progress to next
}


long long
timeInNanos (void)
{
  struct timeval tv;

  gettimeofday (&tv, NULL);
  return (((long long) tv.tv_sec)) + (tv.tv_usec);
}
