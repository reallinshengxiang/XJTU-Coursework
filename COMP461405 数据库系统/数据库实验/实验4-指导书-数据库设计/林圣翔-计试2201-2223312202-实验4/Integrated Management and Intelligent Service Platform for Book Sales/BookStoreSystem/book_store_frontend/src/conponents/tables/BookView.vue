<template>
  <div>
    <el-table :data="books" style="width: 100%">
      <el-table-column prop="id" label="ID" />
      <el-table-column label="书名">
        <template #default="{ row }">
          <el-link @click="goToBookDetailByTitle(row.id)">{{ row.title }}</el-link>
        </template>
      </el-table-column>
      <el-table-column prop="author" label="作者" />
      <el-table-column prop="publisher_id" label="出版社 ID" />
      <el-table-column prop="stock_quantity" label="库存数量" />
      <el-table-column prop="price" label="价格" />
      <el-table-column prop="rating" label="评分" />
      <el-table-column label="操作">
        <template #default="{ row }">
          <el-input v-model="row.newStock" placeholder="输入新库存" style="width: 100px; display: inline-block; margin-right: 10px;" />
          <el-button @click="updateStock(row.id, row.newStock)">修改库存</el-button>
        </template>
      </el-table-column>
    </el-table>
    <el-pagination
      @size-change="handleSizeChange"
      @current-change="handleCurrentChange"
      :current-page="currentPage"
      :page-sizes="[10, 20, 30, 40]"
      :page-size="pageSize"
      layout="total, sizes, prev, pager, next, jumper"
      :total="total"
    />
  </div>
</template>

<script setup>
import { ref, onMounted } from 'vue';
import { getBooksPaginated, adminBookStock } from '@/api/index';
import { useRouter } from 'vue-router';
import { useStore } from 'vuex';

const router = useRouter();
const store = useStore();

const books = ref([]);
const currentPage = ref(1);
const pageSize = ref(20);
const total = ref(0);

const fetchBooks = async () => {
  try {
    const response = await getBooksPaginated(currentPage.value, pageSize.value);
    books.value = response.data.books;
    total.value = response.data.total;
  } catch (error) {
    console.error('获取书籍列表失败:', error);
  }
};

const updateStock = async (bookId, newStock) => {
  try {
    await adminBookStock(bookId).post({ 'stock_quantity': newStock }, {});
    console.log('库存更新成功');
    fetchBooks();
  } catch (error) {
    console.error('更新库存失败:', error);
  }
};

const handleSizeChange = (newSize) => {
  pageSize.value = newSize;
  fetchBooks();
};

const handleCurrentChange = (newPage) => {
  currentPage.value = newPage;
  fetchBooks();
};

const goToBookDetailByTitle = (bookId) => {
  store.dispatch('set_detailid', bookId);
  router.push('/index/bookdetail');
};

onMounted(() => {
  fetchBooks();
});
</script>

<style scoped>
/* 可添加自定义样式 */
</style>