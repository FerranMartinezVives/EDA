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
   using VP = vector<P>;
   using VVP = vector<VP>;
   using VI = vector<int>;
   using VVI = vector<VI>;

   const vector<Dir> dirs = {Up, Down, Left, Right};
   map<int, Pos> info_units;

   //return.first = distància, return.second = índex de dirs
   P bfs(int x, int y, char c) {
     const VI inc_x = {-1, 1, 0, 0};
     const VI inc_y = {0, 0, -1, 1};
     VVP direccions(board_rows(), VP(board_cols(), P(-1, -1)));
     queue<P> Q;
     Q.push(P(x, y));
     direccions[x][y] = P(0, -1);
     while (not Q.empty()) {
       P p = Q.front();
       Q.pop();
       int i = p.first;
       int j = p.second;
       for (int d = 0; d < 4; ++d) {
         int i2 = i + inc_x[d];
         int j2 = j + inc_y[d];
         if (pos_ok(i2, j2) and direccions[i2][j2].first == -1) {
           direccions[i2][j2].first = direccions[i][j].first + 1;
           if (direccions[i][j].first == 0) direccions[i2][j2].second = d;
           else direccions[i2][j2].second = direccions[i][j].second;
           Cell new_cell = cell(i2, j2);
           if (c == 'f' and new_cell.food) return direccions[i2][j2];
           else if (c == 'e' and new_cell.id != -1 and new_cell.owner != me() and unit(new_cell.id).type == Alive) return direccions[i2][j2];
           else if (c == 'z' and new_cell.id != -1 and new_cell.owner == -1) return direccions[i2][j2];
           if (new_cell.type != Waste) Q.push(P(i2, j2));
         }
       }
     }
     return P(-1, -1);
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

      P dir_menjar = bfs(current_pos.i, current_pos.j, 'f');
      P dir_enemic = bfs(current_pos.i, current_pos.j, 'e');
      P dir_zombie = bfs(current_pos.i, current_pos.j, 'z');

      //si hi ha una unitat adjacent, mou-te
      if (dir_enemic.first == 1) {
        it->second = current_pos;
        move(u, dirs[dir_enemic.second]);
      }
      else if (dir_zombie.first == 1) {
        it->second = current_pos;
        move(u, dirs[dir_zombie.second]);
      }

      //prioritza moviment cap a menjar, a no ser que hi hagi un enemic molt més a prop
      else if (dir_menjar.first != -1 and dir_enemic.first != -1 and dir_menjar.first > 3.5 * dir_enemic.first) {
        it->second = current_pos;
        move(u, dirs[dir_enemic.second]);
      }
      else if (dir_menjar.first != -1) {
        it->second = current_pos;
        move(u, dirs[dir_menjar.second]);
      }
      else if (dir_enemic.first != -1) {
        it->second = current_pos;
        move(u, dirs[dir_enemic.second]);
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
