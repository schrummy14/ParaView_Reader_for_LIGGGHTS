#ifndef _liggghts_reader_gz_h
#define _liggghts_reader_gz_h

#include "vtkPolyDataAlgorithm.h"
#include "liggghts_reader_modModule.h"


#include "vtkInformationIntegerKey.h"

class LIGGGHTS_READER_MOD_EXPORT liggghts_reader_gz : public vtkPolyDataAlgorithm
{
public:
	vtkTypeMacro(liggghts_reader_gz, vtkPolyDataAlgorithm);
	static liggghts_reader_gz *New();


	void PrintSelf(ostream& os, vtkIndent indent);
	// Specify file name.
	vtkSetStringMacro(FileName);
	vtkGetStringMacro(FileName);

	int CanReadFile(const char* fname);

protected:
	liggghts_reader_gz();
	~liggghts_reader_gz();
	int RequestInformation(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
	int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *);
	int Canreadfile(const char *fname);
	char *FileName;
	char *FieldDelimiterCharacters;

	size_t NumberOfPoints;

	void OpenFile();
	ifstream *File;

private:
	liggghts_reader_gz(const liggghts_reader_gz&);
	void operator = (const liggghts_reader_gz&);
};
#endif
