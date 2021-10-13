#include "Adafruit_MCP23017.h"
Adafruit_MCP23017 mcp[8];
int i, j, state = 0;
unsigned long current_time, previous_time = 0;

void setup()
{
  for (j=0; j<8; j++)
  {
    mcp[j].begin(j);
  }
  for(j=0; j<8; j++)
  {
    for(i=0; i<16; i++)
    {
      mcp[j].pinMode(i, OUTPUT);
    }
  }
}

void loop()
{
  for (j=0; j<8; j++)
  {
    state = 0;
    while (state != 2)
    {
      current_time = millis();
      if (current_time - previous_time >= 500)
      {
        previous_time = current_time;
        if (state == 0)
        {
          state = 1;
          for (i=0; i<16; i++)
          {
            mcp[j].digitalWrite (i, state);
          }
        }
        else if (state == 1)
        {
          state = 0;
          for (i=0; i<16; i++)
          {
            mcp[j].digitalWrite (i, state);
          }
          state = 2;
        }
      }
    }
  }
}
