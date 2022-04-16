#ifndef STONNE_TILEGENERATOR_H
#define STONNE_TILEGENERATOR_H

#include "Tiles.h"
#include "TileGenerator/mRNA/define.h"

namespace TileGenerator {

    enum Target {
        NONE = mRNA::none,
        PERFORMANCE = mRNA::performance,
        ENERGY = mRNA::energy,
        ENERGY_EFFICIENCY = mRNA::energy_efficiency
    };

    class TileGenerator {
    private:
        uint num_ms;
        uint dn_bw;
        uint rn_bw;

    public:
        TileGenerator(int num_ms, int dn_bw, int rn_bw) : num_ms(num_ms), dn_bw(dn_bw), rn_bw(rn_bw) {}
        ~TileGenerator() = default;

        ConvTile generateConvTile(uint R, uint S, uint C, uint K, uint G, uint N, uint X, uint Y, uint X_, uint Y_,
                                  uint stride, Target target);

        DenseGemmTile generateDenseGemmTile(uint M, uint N, uint K, Target target);

        SparseDenseTile generateSparseDenseTile(uint M, uint N, uint K, float MK_sparsity);
    private:

    };

} // TileGenerator

#endif //STONNE_TILEGENERATOR_H