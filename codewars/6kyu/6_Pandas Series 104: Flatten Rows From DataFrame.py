def flatten(df, col):
    return df.copy().explode(col).reset_index(drop=True)