#include "Classes.h"

int main()
{
  std::cout << "Start Design Pattern Demonstration: Memento" << std::endl;
  std::cout << std::endl;
 
  ContextHistory contextHistory;
  Context context;
  std::cout << std::endl;
  
  /* initialize ncurses data structures and read terminfo file */
  initscr();
  
  /* backspace fix */
  keypad(stdscr, TRUE);
  
  /* disables line buffering and erase/kill character-processing,
   * making characters typed immediately available to the program */
  cbreak();
  
  /* buffer string to be printed on screen */
  addstr("Type a simple text and press enter to exit\n\r");
  
  /* print buffered strings on screen */
  refresh();
  
  while(1)
  {
    context.setCharacter(getch());
    contextHistory.add(context.saveContext());
    
    if(context.getCharacter() == '\n')
      break;
  }
  
  /* Clean up all allocated resources from ncurses and restore the tty 
   * modes to the status they had before calling initscr() */
  endwin();
  
  std::cout << std::endl;
  contextHistory.show();
  
  std::cout << std::endl;
  std::cout << "End Design Pattern Demonstration: Memento" << std::endl;
  std::cout << std::endl;
  return(0);
}
