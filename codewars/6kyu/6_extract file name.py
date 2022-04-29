class FileNameExtractor:
    @staticmethod
    def extract_file_name(x):
        return x.split('_', 1)[1].rsplit('.', 1)[0]
