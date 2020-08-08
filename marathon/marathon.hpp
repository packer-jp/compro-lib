void simulated_annealing() {
    timer.init();
    double T = 5.95;
    double start_temp = 0.01;
    double end_temp = 0.01;
    int it = 0, pre_score;
    double time;
    while ((time = timer.get_time()) < T) {
        it++;
        double temp = start_temp + (end_temp - start_temp) * time / T;
        int new_score;
        // スコアが高いほどいい
        double prob = exp((new_score - pre_score) / temp);
        if (prob < (double) xor64(10000000) / 10000000) {
            // rejected
        } else {
            // accepted
        }
    }
}

struct state {
    int val;
};
state beam_search() {
    int T = 1000;
    int beam_width = 100;
    vector<state> pre_states;
    for (int i = 0; i < T; i++) {
        vector<state> next_states;
        // pre_statesから次の状態を計算しnext_statesに突っ込む
        vector<int> idx(next_states.size());
        for (int i = 0; i < idx.size(); i++) { idx[i] = i; }
        nth_element(idx.begin(), idx.begin() + beam_width - 1, idx.end(), [&](int l, int r) {
            // lのほうが優先度が高い時、true
            return next_states[l].val > next_states[r].val;
        });
        pre_states.clear();
        for (int i = 0; i < min(beam_width, (int) idx.size()); i++) {
            pre_states.push_back(next_states[idx[i]]);
        }
    }
    state ret;
    for (int i = 0; i < pre_states.size(); i++) {
        if (ret.val < pre_states[i].val) { ret = pre_states[i]; }
    }
    return ret;
}