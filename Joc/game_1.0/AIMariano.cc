#include "Player.hh"
#include<iostream>
#include<vector>
#include<map>
#include<queue>

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Mariano


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
   using P = pair<int, int>;
   using VI = vector<int>;
   using VVI = vector<VI>;

   const vector<Dir> dirs = {Up, Down, Left, Right};
   map<int, Pos> info_units;
   VI inc_x = {0, 0, -1, 1};
   VI inc_y = {-1, 1, 0, 0};

   int bfs(int x, int y) {

     if (x % 2 == 0) return 1;
     else return -1;
     /*queue<P> cua;
     VVI dists(board_rows(), VI(board_cols(), -1));
     cua.push(P(x, y));
     dists[x][y] = 0;
     int its = 0;
     while (not cua.empty() and its < 15) {
       P p = cua.front();
       cua.pop();
       int i = p.first;
       int j = p.second;
       for (int d = 0; d < 4; ++d) {
         int i2 = i + inc_x[d];
         int j2 = j + inc_y[d];
         if (pos_ok(i2, j2) and dists[i2][j2] == -1) {
           dists[i2][j2] = dists[i][j] + 1;
           Cell new_cell = cell(i2, j2);
           if (new_cell.food) dists[i2][j2];
           if (new_cell.type != Waste) cua.push(P(i2, j2));
         }
       }
       ++its;
     }
     return -1;*/
   }


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {

    if (status(me()) >= 0.95) return;

    vector<int> units = alive_units(me());
    for (int u : units) {
      vector<int> rand = random_permutation(4);
      Pos current_pos = unit(u).pos;
      auto it = info_units.find(u);
      if (info_units.find(u) == info_units.end()) info_units.insert(make_pair(u, current_pos));

      int dist_menjar = bfs(current_pos.i, current_pos.j);
      if (dist_menjar == -1) cerr << "no s'ha trobat menjar" << endl;
      else cerr << "s'ha trobat menjar a distancia " << dist_menjar << endl;

      //si hi ha menjar, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos new_pos = current_pos + dirs[rand[d]];
        if (pos_ok(new_pos)) {
          Cell new_cell = cell(new_pos);
          if (new_cell.food) {
            it->second = current_pos;
            move(u, dirs[rand[d]]);
          }
        }
      }

      //si la casella no és nostra, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos new_pos = current_pos + dirs[rand[d]];
        if (pos_ok(new_pos)) {
          Cell new_cell = cell(new_pos);
          if (new_cell.type != Waste and new_cell.owner != me()) {
            it->second = current_pos;
            move(u, dirs[rand[d]]);
          }
        }
      }
      //si no és l'anterior, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos new_pos = current_pos + dirs[rand[d]];
        if (pos_ok(new_pos)) {
          Cell new_cell = cell(new_pos);
          if (new_pos != it->second and new_cell.type != Waste) {
            it->second = current_pos;
            move(u, dirs[rand[d]]);
          }
        }
      }
      //si no és deixalla, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos new_pos = current_pos + dirs[rand[d]];
        if (pos_ok(new_pos)) {
          Cell new_cell = cell(new_pos);
          if (new_cell.type != Waste) {
            it->second = current_pos;
            move(u, dirs[rand[d]]);
          }
        }
      }
    }
  }
};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
