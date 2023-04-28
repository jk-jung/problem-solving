def is_mac_48_address(x):
    try:
        assert len(x) == 17
        x = x.split('-')
        for i in range(6):
            assert len(x[i]) == 2
            assert '0' <= x[i][0] <= '9' or 'A' <= x[i][0] <= 'F'
            assert '0' <= x[i][1] <= '9' or 'A' <= x[i][1] <= 'F'
        return True
    except: return False
