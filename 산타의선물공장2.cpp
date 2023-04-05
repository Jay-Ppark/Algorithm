#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_N 100000
#define MAX_M 100000

using namespace std;

int n, m, q;

// id에 해당하는 상자의 nxt값과 prv값을 관리합니다.
// 0이면 없다는 뜻입니다.
int prv[MAX_M + 1], nxt[MAX_M + 1];

// 각 벨트별로 head, tail id, 그리고 총 선물 수를 관리합니다.
// 0이면 없다는 뜻입니다.
int head[MAX_N], tail[MAX_N], num_gift[MAX_N];

// 공장 설립
void BuildFactory() {
    // 공장 정보를 입력받습니다.
    cin >> n >> m;
    
    // 벨트 정보를 만들어줍니다.
    vector<int> boxes[MAX_N];
    for(int id = 1; id <= m; id++) {
        int b_num;
        cin >> b_num;
        b_num--;
        
        boxes[b_num].push_back(id);
    }

    // 초기 벨트의 head, tail, nxt, prv값을 설정해줍니다.
    for(int i = 0; i < n; i++) {
        // 비어있는 벨트라면 패스합니다.
        if((int) boxes[i].size() == 0)
            continue;
        
        // head, tail을 설정해줍니다.
        head[i] = boxes[i].front();
        tail[i] = boxes[i].back();

        // 벨트 내 선물 총 수를 관리해줍니다.
        num_gift[i] = (int) boxes[i].size();

        // nxt, prv를 설정해줍니다.
        for(int j = 0; j < (int) boxes[i].size() - 1; j++) {
            nxt[boxes[i][j]] = boxes[i][j + 1];
            prv[boxes[i][j + 1]] = boxes[i][j];
        }
    }
}

// 물건을 전부 옮겨줍니다.
void Move() {
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;

    // m_src에 물건이 없다면
    // 그대로 m_dst내 물건 수가 답이 됩니다.
    if(num_gift[m_src] == 0) {
        cout << num_gift[m_dst] << endl;
        return;
    }

    // m_dst에 물건이 없다면
    // 그대로 옮겨줍니다.
    if(num_gift[m_dst] == 0) {
        head[m_dst] = head[m_src];
        tail[m_dst] = tail[m_src];
    }
    else {
        int orig_head = head[m_dst];
        // m_dst의 head를 교체해줍니다.
        head[m_dst] = head[m_src];
        // m_src의 tail과 기존 m_dst의 head를 연결해줍니다.
        int src_tail = tail[m_src];
        nxt[src_tail] = orig_head;
        prv[orig_head] = src_tail;
    }

    // head, tail을 비워줍니다.
    head[m_src] = tail[m_src] = 0;

    // 선물 상자 수를 갱신해줍니다.
    num_gift[m_dst] += num_gift[m_src];
    num_gift[m_src] = 0;

    cout << num_gift[m_dst] << endl;
}

// 해당 벨트의 head를 제거합니다.
int RemoveHead(int b_num) {
    // 불가능하면 패스합니다.
    if(!num_gift[b_num])
        return 0;
    
    // 노드가 1개라면
    // head, tail 전부 삭제 후
    // 반환합니다.
    if(num_gift[b_num] == 1) {
        int id = head[b_num];
        head[b_num] = tail[b_num] = 0;
        num_gift[b_num] = 0;
        return id;
    }

    // head를 바꿔줍니다.
    int hid = head[b_num];
    int next_head = nxt[hid];
    nxt[hid] = prv[next_head] = 0;
    num_gift[b_num]--;
    head[b_num] = next_head;

    return hid;
}

// 해당 밸트에 head를 추가합니다.
void PushHead(int b_num, int hid) {
    // 불가능한 경우는 진행하지 않습니다.
    if(hid == 0)
        return;

    // 비어있었다면
    // head, tail이 동시에 추가됩니다.
    if(!num_gift[b_num]) {
        head[b_num] = tail[b_num] = hid;
        num_gift[b_num] = 1;
    }
    // 그렇지 않다면
    // head만 교체됩니다.
    else {
        int orig_head = head[b_num];
        nxt[hid] = orig_head;
        prv[orig_head] = hid;
        head[b_num] = hid;
        num_gift[b_num]++;
    }
}

// 앞 물건을 교체해줍니다.
void Change() {
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;
    
    int src_head = RemoveHead(m_src);
    int dst_head = RemoveHead(m_dst);
    PushHead(m_dst, src_head);
    PushHead(m_src, dst_head);
    
    cout << num_gift[m_dst] << endl;
}

// 물건을 나눠옮겨줍니다.
void Divide() {
    int m_src, m_dst;
    cin >> m_src >> m_dst;
    m_src--; m_dst--;

    // 순서대로 src에서 박스들을 빼줍니다.
    int cnt = num_gift[m_src];
    vector<int> box_ids;
    for(int i = 0; i < cnt / 2; i++)
        box_ids.push_back(RemoveHead(m_src));
    
    // 거꾸로 뒤집어서 하나씩 dst에 박스들을 넣어줍니다.
    for(int i = (int) box_ids.size() - 1; i >= 0; i--)
        PushHead(m_dst, box_ids[i]);

    cout << num_gift[m_dst] << endl;
}

// 선물 점수를 얻습니다.
void GiftScore() {
    int p_num;
    cin >> p_num;

    int a = prv[p_num] != 0 ? prv[p_num] : -1;
    int b = nxt[p_num] != 0 ? nxt[p_num] : -1;

    cout << a + 2 * b << endl;
}

// 벨트 정보를 얻습니다.
void BeltScore() {
    int b_num;
    cin >> b_num;
    b_num--;

    int a = head[b_num] != 0 ? head[b_num] : -1;
    int b = tail[b_num] != 0 ? tail[b_num] : -1;
    int c = num_gift[b_num];

    cout << a + 2 * b + 3 * c << endl;
}

int main() {
    // 입력:
    cin >> q;
    while(q--) {
        int q_type;
        cin >> q_type;
        if(q_type == 100)
            BuildFactory();
        else if(q_type == 200)
            Move();
        else if(q_type == 300)
            Change();
        else if(q_type == 400)
            Divide();
        else if(q_type == 500)
            GiftScore();
        else
            BeltScore();
    }
    return 0;
}