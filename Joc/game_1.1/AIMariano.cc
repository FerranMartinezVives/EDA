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

   int bfs(int x, int y) {
     const VI inc_x = {-1, 1, 0, 0};
     const VI inc_y = {0, 0, -1, 1};
     VVI direccions(board_rows(), VI(board_cols(), -1));
     queue<P> Q;
     Q.push(P(x, y));
     direccions[x][y] = 0;
     while (not Q.empty()) {
       P p = Q.front();
       Q.pop();
       int i = p.first;
       int j = p.second;
       for (int d = 0; d < 4; ++d) {
         int i2 = i + inc_x[d];
         int j2 = j + inc_y[d];
         if (pos_ok(i2, j2) and direccions[i2][j2] == -1) {
           if (direccions[i][j] == 0) direccions[i2][j2] = d + 1;
           else direccions[i2][j2] = direccions[i][j];
           Cell new_cell = cell(i2, j2);
           if (new_cell.food) return direccions[i2][j2] - 1;
           if (new_cell.type != Waste) Q.push(P(i2, j2));
         }
       }
     }
     return -1;
   }


  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {

    if (status(me()) >= 0.95) return;

    VI units = alive_units(me());
    for (int u : units) {
      VI rand = random_permutation(4);
      Pos current_pos = unit(u).pos;
      auto it = info_units.find(u);
      if (info_units.find(u) == info_units.end()) info_units.insert(make_pair(u, current_pos));

      //si hi ha una unitat enemiga adjacent, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos new_pos = current_pos + dirs[rand[d]];
        if (pos_ok(new_pos)) {
          Cell new_cell = cell(new_pos);
          if (new_cell.id != -1 and new_cell.owner != me() and unit(new_cell.id).type != Dead) {
            it->second = current_pos;
            move(u, dirs[rand[d]]);
          }
        }
      }

      //si hi ha un zombie en diagonal, mou-te
      for (int d = 0; d < 4; ++d) {
        Pos diag_pos = current_pos + dirs[d / 2] + dirs[2 + d % 2];
        if (pos_ok(diag_pos)) {
          Cell diag_cell = cell(diag_pos);
          if (diag_cell.id != -1 and unit(diag_cell.id).type == Zombie) {
            Pos new_pos = current_pos + dirs[d / 2];
            if (pos_ok(new_pos) and cell(new_pos).type != Waste) {
              it->second = current_pos;
              move(u, dirs[d / 2]);
            }
            else {
              new_pos = current_pos + dirs[2 + d % 2];
              if (pos_ok(new_pos) and cell(new_pos).type != Waste) {
                it->second = current_pos;
                move(u, dirs[2 + d % 2]);
              }
            }
          }
        }
      }

      //si hi ha menjar, mou-te
      int dir_menjar = bfs(current_pos.i, current_pos.j);
      if (dir_menjar != -1) {
        it->second = current_pos;
        move(u, dirs[dir_menjar]);
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
