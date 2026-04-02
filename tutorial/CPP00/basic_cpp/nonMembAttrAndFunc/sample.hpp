#ifndef SAMPLE_HPP
#define SAMPLE_HPP

class sample {
	public:
		sample();
		~sample();
		
		static int	getMbInst();
	
	private:
		static int	_mbInst;
};

#endif